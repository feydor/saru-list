src = ['main.c', 'dlist.c']

libsaru_list = library(
  'saru-list',
  src,
  include_directories: inc,
  install: true
)

libsaru_list_dep = declare_dependency(
  include_directories: inc,
  link_with: libsaru_list
)

exe = executable('saru_list',
  src,
  include_directories: inc,
  link_with: libsaru_list,
  c_args: ['-Wall'],
  install : true
)

test('basic', exe)
