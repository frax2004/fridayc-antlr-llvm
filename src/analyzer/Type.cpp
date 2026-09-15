#include <fridayc.hpp>


namespace friday::inline api {
  auto Type::size() const -> u64 {
    return LLVM.size_of(this->to_llvm_type());
  }

  auto Type::to_llvm_abi_type() const noexcept -> llvm::Type* {
    auto self = const_cast<Type*>(this);
    if(not self->is_aggregate_type()) return this->to_llvm_type();

    u64 size = this->size();
    if(size == 0) return LLVM.get_void_type();
    if(size <= 1) return LLVM.get_int_type(8);
    if(size <= 2) return LLVM.get_int_type(16);
    if(size <= 4) return LLVM.get_int_type(32);
    if(size <= 8) return LLVM.get_int_type(64);

    return this->to_llvm_type();
  }

  auto Type::alignment() const -> u64 {
    return LLVM.alignment_of(this->to_llvm_type());
  }

  auto Type::get_c_short_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("c_short"));
  }

  auto Type::get_c_int_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("c_int"));
  }

  auto Type::get_c_float_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("c_float"));
  }

  auto Type::get_int_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("int"));
  }

  auto Type::get_byte_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("byte"));
  }

  auto Type::get_bool_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("bool"));
  }

  auto Type::get_float_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("float"));
  }

  auto Type::get_voidptr_type() -> Type* {
    return PointerType::get(*Type::get_void_type(), 1);
  }

  auto Type::get_byteptr_type() -> Type* {
    return PointerType::get(*Type::get_byte_type(), 1);
  }

  auto Type::get_void_type() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("void"));
  }

  auto Type::get_overload_type() -> Type* {
    return UnresolvedOverloadType::get();
  }

  auto Type::get_type_type() -> Type* {
    return TypeType::get();
  }

  auto Type::get_namespace_type() -> Type* {
    return NamespaceType::get();
  }

  auto Type::is_primitive_type() -> bool {
    return PrimitiveType::is_primitive(this);
  }

  auto Type::is_slice_type() -> bool {
    return ArrayType::is_array(this);
  }

  auto Type::is_pointer_type() -> bool {
    return PointerType::is_pointer(this);
  }

  auto Type::is_aggregate_type() -> bool {
    return Struct::is_struct_type(this) and not this->is_primitive_type();
  }

  auto Type::is_overload_type() -> bool {
    return UnresolvedOverloadType::is_unresolved_overload_type(this);
  }

  auto Type::is_function_type() -> bool {
    return FunctionType::is_function(this);
  }

  auto Type::is_type_type() -> bool {
    return TypeType::is_type_type(this);
  }

  auto Type::is_namespace_type() -> bool {
    return NamespaceType::is_namespace_type(this);
  }

  auto Type::is_error_type() -> bool {
    return ErrorType::is_error_type(this);
  }

  auto Type::is_integral_type() -> bool {
    return this->is_primitive_type() and this->to_llvm_type()->isIntegerTy();
  }

  auto Type::is_floating_type() -> bool {
    return this->is_primitive_type() and this->to_llvm_type()->isFloatingPointTy();
  }

  auto Type::is_convertible_to(Type* to) -> optional<llvm::Instruction::CastOps> {
    using key_type = pair<Type*, Type*>;
    using value_type = llvm::Instruction::CastOps;
    using comparator_type = less<key_type>;
    using coercion_table_type = map<key_type, value_type, comparator_type>;
    
    // false if other is a null instance
    if(to == nullptr) return nullopt;
    
    // true if this type is the same as "to"
    if(this == to) return llvm::Instruction::BitCast;

    // true if they are both pointers of some kind
    if(this->is_pointer_type() and to->is_pointer_type()) 
      return llvm::Instruction::BitCast;

    static Type* INT = Type::get_int_type();
    static Type* BYTE = Type::get_byte_type();
    static Type* BOOL = Type::get_bool_type();
    static Type* FLOAT = Type::get_float_type();
    static Type* VOIDPTR = Type::get_voidptr_type();

    static Type* CSHORT = Type::get_c_short_type();
    static Type* CINT = Type::get_c_int_type();
    static Type* CFLOAT = Type::get_c_float_type();

    Type* lhs = this->is_pointer_type() ? VOIDPTR : this;
    Type* rhs = to->is_pointer_type() ? VOIDPTR : to;

    static coercion_table_type S_coercionTable {
      pair{ pair{ VOIDPTR , INT     }, llvm::Instruction::CastOps::PtrToInt },
      pair{ pair{ INT     , VOIDPTR }, llvm::Instruction::CastOps::IntToPtr },

      pair{ pair{ FLOAT   , INT     }, llvm::Instruction::CastOps::FPToSI   },
      pair{ pair{ INT     , FLOAT   }, llvm::Instruction::CastOps::SIToFP   },

      pair{ pair{ FLOAT   , CFLOAT }, llvm::Instruction::CastOps::FPTrunc  },
      pair{ pair{ CFLOAT  , FLOAT  }, llvm::Instruction::CastOps::FPExt    },

      pair{ pair{ INT     , BYTE    }, llvm::Instruction::CastOps::Trunc    },
      pair{ pair{ BYTE    , INT     }, llvm::Instruction::CastOps::SExt     },
      
      pair{ pair{ INT     , BOOL    }, llvm::Instruction::CastOps::Trunc    },
      pair{ pair{ BOOL    , INT     }, llvm::Instruction::CastOps::ZExt     },

      pair{ pair{ INT     , CINT    }, llvm::Instruction::CastOps::Trunc    },
      pair{ pair{ CINT    , INT     }, llvm::Instruction::CastOps::SExt     },

      pair{ pair{ INT     , CSHORT  }, llvm::Instruction::CastOps::Trunc    },
      pair{ pair{ CSHORT  , INT     }, llvm::Instruction::CastOps::SExt     },
    };

    if(
      auto iter = S_coercionTable.find(make_pair(lhs, rhs)); 
      iter != S_coercionTable.end()
    ) {
      return iter->second;
    } else return nullopt;
  }
}