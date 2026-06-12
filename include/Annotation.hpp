#pragma once
#include <FridayParser.h>
#include <VisibilityModifier.hpp>
#include <Type.hpp>



namespace friday::inline api::inline pipeline {

  struct TypeAnnotation {
    Type* type;
  };

  struct VarAnnotation {
    Type*              type { nullptr };
    VisibilityModifier visibility {};
    bool               isConst { false };
  };

  struct FuncAnnotation {
    ISymbolTable*      scope { nullptr };
    Type*              type { nullptr };
    VisibilityModifier visibility {};
    bool               isStatic { false };
    bool               isNative { false };
  };

  template<class... Properties>
  struct AnnotationTree {
    public:
    using annotation_type = variant<Properties...>;
    using key_type = ant::Token*;
    using tree_type = unordered_map<key_type, annotation_type>;

    private:
    tree_type M_properties;

    public:
    auto setMetadata(key_type key, annotation_type metadata) -> void;

    template<class T>
    requires (same_as<T, Properties> or ...)
    auto isAnnotatedWith(key_type key) const -> bool;

    template<class T>
    requires (same_as<T, Properties> or ...)
    auto getMetadata(key_type key) const -> optional<T>;

    template<class T>
    requires (same_as<T, Properties> or ...)
    auto getMetadata(key_type key, T fallback) const -> T;

    auto operator[](key_type key) -> annotation_type&;
  };

  using DefaultAnnotationTree = AnnotationTree<
    TypeAnnotation,
    VarAnnotation,
    FuncAnnotation
  >;
}


#include <Annotation.inl>