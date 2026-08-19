#pragma once

//* ////////////////////////////////////////
//* /// Core
//* ////////////////////////////////////////
#include <fridayc/Version.hpp>
#include <fridayc/Core.hpp>
#include <fridayc/Common.hpp>
//* ////////////////////////////////////////


//* ////////////////////////////////////////
//* /// Errors
//* ////////////////////////////////////////
#include <fridayc/Errors.hpp>
#include <fridayc/SemanticError.hpp>
//* ////////////////////////////////////////


//* ////////////////////////////////////////
//* /// Utility
//* ////////////////////////////////////////
#include <fridayc/SourceLocation.hpp>
#include <fridayc/Debugging.hpp>
#include <fridayc/Metadata.hpp>
#include <fridayc/Value.hpp>
#include <fridayc/TranslationUnit.hpp>
#include <fridayc/CompilationContext.hpp>
#include <fridayc/CompilationSettings.hpp>
#include <fridayc/NameMangler.hpp>
#include <fridayc/GrammarAttributes.hpp>
#include <fridayc/SignatureLess.hpp>
//* ////////////////////////////////////////


//* ////////////////////////////////////////
//* /// Types
//* ////////////////////////////////////////
#include <fridayc/Type.hpp>
#include <fridayc/BuiltinTypes.hpp>
//* ////////////////////////////////////////


//* ////////////////////////////////////////
//* /// Symbols
//* ////////////////////////////////////////
#include <fridayc/Symbol.hpp>
#include <fridayc/Variable.hpp>
#include <fridayc/Function.hpp>
#include <fridayc/Overload.hpp>
#include <fridayc/Struct.hpp>
//* ////////////////////////////////////////


//* ////////////////////////////////////////
//* /// SymbolTables
//* ////////////////////////////////////////
#include <fridayc/SymbolTable.hpp>
#include <fridayc/Scope.hpp>
#include <fridayc/Namespace.hpp>
//* ////////////////////////////////////////


//* ////////////////////////////////////////
//* /// Compiler
//* ////////////////////////////////////////
#include <fridayc/StaticAnalyzer.hpp>
#include <fridayc/DiscoveryVisitor.hpp>
#include <fridayc/NamespaceBindingVisitor.hpp>
#include <fridayc/TypeSolverVisitor.hpp>
#include <fridayc/OverloadSolverVisitor.hpp>
#include <fridayc/TypeCheckerVisitor.hpp>
#include <fridayc/LLVMObjectEmitterVisitor.hpp>
#include <fridayc/LinkerVisitor.hpp>
#include <fridayc/Compiler.hpp>
//* ////////////////////////////////////////