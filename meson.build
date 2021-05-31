project('saru-list', 'c',
  version : '0.1.0',
  default_options : ['warning_level=3', c_std='c11', 
    'c_link_args=-fsanitize=address,undefined'])

src = ['src/saru_list.c']
inc = include_directories('inc')

exe = executable('saru_list',
  src,
  install : true)

test('basic', exe)
