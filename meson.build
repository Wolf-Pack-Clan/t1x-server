# Define the project
project('t1x-server', 'cpp',
  default_options: ['cpp_std=c++11', 'warning_level=3', 'buildtype=release'])

# Retrieve option values from meson_options.txt
enable_unsafe = get_option('enable_unsafe')
#compile_sqlite = get_option('compile_sqlite')
compile_curl = get_option('compile_curl')
compile_ssl = get_option('compile_ssl')

# Print configuration messages
message('---------------------')
message('Target: ' + get_option('buildtype'))
message('Risky features: ' + enable_unsafe.to_string())
#message('SQLite: ' + compile_sqlite.to_string())
message('cURL: ' + compile_curl.to_string())
message('SSL: ' + compile_ssl.to_string())
message('---------------------')

# Set base compiler and linker flags for 32-bit compilation
add_project_arguments('-m32', '-fpic', '-fvisibility=hidden', language: 'cpp')
add_project_link_arguments('-m32', language: 'cpp')

# Handle debug build flags and definitions
if get_option('buildtype') == 'debug'
  #add_project_arguments('-g', '-ggdb', '-DDEBUG', language: 'cpp')
  add_project_arguments('-DDEBUG', language: 'cpp')
  #add_project_link_arguments('-g', language: 'cpp')
else
# Is it safe?
  add_project_arguments('-Wno-strict-aliasing', language: 'cpp')
endif

# Handle ENABLE_UNSAFE definition
if enable_unsafe
  add_project_arguments('-DENABLE_UNSAFE=1', language: 'cpp')
else
  add_project_arguments('-DENABLE_UNSAFE=0', language: 'cpp')
endif

# Dependencies
deps = [
  dependency('dl'),
  dependency('threads')
]

'''
# SQLite support
if compile_sqlite
  sqlite_dep = dependency('sqlite3')
  if not sqlite_dep.found()
    error('SQLite requested but library not found.')
  endif
  add_project_arguments('-DCOMPILE_SQLITE=1', language: 'cpp')
  deps += sqlite_dep
else
  add_project_arguments('-DCOMPILE_SQLITE=0', language: 'cpp')
endif
'''

# cURL support
if compile_curl
  curl_dep = dependency('libcurl')
  if not curl_dep.found()
    error('cURL requested but library not found.')
  endif
  add_project_arguments('-DCOMPILE_CURL=1', language: 'cpp')
  deps += curl_dep
else
  add_project_arguments('-DCOMPILE_CURL=0', language: 'cpp')
endif

# SSL support with OpenSSL
if compile_ssl
  openssl_dep = dependency('openssl')
  if not openssl_dep.found()
    error('OpenSSL requested but library not found.')
  endif
  add_project_arguments('-DCOMPILE_SSL=1', language: 'cpp')
  deps += openssl_dep
else
  add_project_arguments('-DCOMPILE_SSL=0', language: 'cpp')
endif

# Source files
sources = [
  'src/art.cpp',
  'src/gsc/gsc.cpp',
  'src/gsc/gsc_curl.cpp',
  'src/gsc/gsc_player.cpp',
  'src/gsc/gsc_utils.cpp',
  'src/gsc/gsc_weapons.cpp',
  'src/jump.cpp',
  'src/hook.cpp',
  'src/t1x.cpp'
]

# The shared library
t1x = shared_library('t1x',
  sources,
  dependencies: deps,
  name_prefix: '',
  cpp_pch: 'src/pch.h',
  install: true,
  install_dir: 'bin/'
)
