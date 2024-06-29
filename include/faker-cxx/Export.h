#ifndef FAKER_CXX_EXPORT_H
#define FAKER_CXX_EXPORT_H

#ifdef _MSVC
#  ifdef FAKER_CXX_STATIC_DEFINE
#    define FAKER_CXX_EXPORT
#    define FAKER_CXX_NO_EXPORT
#  else
#    ifndef FAKER_CXX_EXPORT
#      ifdef faker_cxx_EXPORTS
         /* We are building this library */
#        define FAKER_CXX_EXPORT __declspec(dllexport)
#      else
          /* We are using this library */
#        define FAKER_CXX_EXPORT __declspec(dllimport)
#      endif
#    endif

#    ifndef FAKER_CXX_NO_EXPORT
#      define FAKER_CXX_NO_EXPORT
#    endif
#  endif

#  ifndef FAKER_CXX_DEPRECATED
#    define FAKER_CXX_DEPRECATED __declspec(deprecated)
#  endif

#  ifndef FAKER_CXX_DEPRECATED_EXPORT
#    define FAKER_CXX_DEPRECATED_EXPORT FAKER_CXX_EXPORT FAKER_CXX_DEPRECATED
#  endif

#  ifndef FAKER_CXX_DEPRECATED_NO_EXPORT
#    define FAKER_CXX_DEPRECATED_NO_EXPORT FAKER_CXX_NO_EXPORT FAKER_CXX_DEPRECATED
#  endif

#  if 0 /* DEFINE_NO_DEPRECATED */
#    ifndef FAKER_CXX_NO_DEPRECATED
#      define FAKER_CXX_NO_DEPRECATED
#    endif
#  endif
#else
#  define FAKER_CXX_EXPORT
#  define FAKER_CXX_NO_EXPORT
#endif

#endif /* FAKER_CXX_EXPORT_H */