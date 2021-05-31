project('saru-list', 'c',
  version : '0.1.0',
  license: 'MIT',
  default_options : ['warning_level=3', 'c_std=c11', 
    'c_link_args=-lasan'])

inc = include_directories('inc')
subdir('src')

install_headers('inc/saru-dlist.h', subdir: 'saru_list')

pkg = import('pkgconfig')
pkg.generate(
  libraries: libsaru_list,
  subdirs: 'inc',
  version: meson.project_version(),
  name: 'libsaru_list',
  filebase: 'saru_list',
  description: 'A simple C library containing buffer data structures. A module of the "saru-" family of libraries.'
)

