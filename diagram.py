import CppHeaderParser as parser
from pathlib import Path

sources = list(str(p) for p in Path('include').glob('*.hpp'))

def clean_name(name):
    """
    Pulisce il nome da template e keyword 'inline' residue.
    Esempio: 'inline MyNamespace::MyClass<T>' -> 'MyNamespace::MyClass'
    """
    if not name:
        return ""
    # Rimuove i template <...>
    name = name.split('<')[0]
    # Rimuove la keyword inline e spazi extra
    name = name.replace("inline", "").strip()
    # Gestisce eventuali doppi due punti residui o spazi
    return name.replace(" ::", "::").replace(":: ", "::")

def format_namespace(ns):
    """Converte il namespace C++ (A::B) nel formato PlantUML (A.B) pulendo 'inline'"""
    if not ns:
        return ""
    parts = ns.split("::")
    # Filtra via 'inline' e parti vuote
    clean_parts = [p.replace("inline", "").strip() for p in parts if p.strip() and p.strip() != "inline"]
    return ".".join(clean_parts)

def toPuml(headers):
    print("@startuml")
    print("set namespaceSeparator .") # Usa il punto come separatore
    
    relationships = set()
    visibility_map = {"public": "+", "protected": "#", "private": "-"}

    for header in headers:
        try:
            ast = parser.CppHeader(header)
        except Exception:
            continue

        for class_name, class_data in ast.classes.items():
            # 1. Pulizia Nomi
            raw_ns = class_data.get("namespace", "")
            clean_ns = format_namespace(raw_ns)
            short_name = clean_name(class_name.split("::")[-1])
            
            # Nome completo per identificare univocamente la classe nei collegamenti
            full_class_path = f"{clean_ns}.{short_name}" if clean_ns else short_name

            # 2. Definizione Classe (dentro namespace se esiste)
            if clean_ns:
                print(f"namespace {clean_ns} {{")
            
            print(f"  class {short_name} {{")
            
            # Metodi e Proprietà
            for access in ["public", "protected", "private"]:
                symbol = visibility_map[access]
                # Proprietà
                for prop in class_data["properties"][access]:
                    print(f"    {symbol}{prop.get('name')} : {prop.get('type')}")
                # Metodi
                for method in class_data["methods"][access]:
                    m_name = method.get("name")
                    rtn = method.get("rtnType", "void")
                    params = ", ".join([f"{p['type']} {p['name']}".strip() for p in method.get("parameters", [])])
                    print(f"    {symbol}{m_name}({params}) : {rtn}")
            
            print("  }")
            
            if clean_ns:
                print("}")

            # 3. Gestione Ereditarietà (fuori dai blocchi per semplicità)
            for base in class_data.get("inherits", []):
                base_raw = base.get("class")
                # Puliamo il nome della base (rimuove template e inline)
                # Nota: qui il parser a volte non dà il namespace completo, 
                # quindi facciamo il meglio possibile pulendo il nome
                base_clean = clean_name(base_raw).replace("::", ".")
                relationships.add(f"{base_clean} <|-- {full_class_path}")

    # Stampa i collegamenti
    for rel in relationships:
        print(rel)

    print("@enduml")

import sys
with open("diagram.puml", "+w") as f:
  sys.stdout = f
  toPuml(sources)