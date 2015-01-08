
#ifndef KUDU_EXPORT_H
#define KUDU_EXPORT_H

#ifdef KUDU_STATIC_DEFINE
#  define KUDU_EXPORT
#  define KUDU_NO_EXPORT
#else
#  ifndef KUDU_EXPORT
#    ifdef kudu_client_EXPORTS
        /* We are building this library */
#      define KUDU_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define KUDU_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef KUDU_NO_EXPORT
#    define KUDU_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef KUDU_DEPRECATED
#  define KUDU_DEPRECATED __attribute__ ((__deprecated__))
#  define KUDU_DEPRECATED_EXPORT KUDU_EXPORT __attribute__ ((__deprecated__))
#  define KUDU_DEPRECATED_NO_EXPORT KUDU_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define KUDU_NO_DEPRECATED
#endif

#endif
