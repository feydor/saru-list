unity_dep = dependency(
  'Unity',
  fallback: ['Unity', 'unity_dep'],
)

sdlist_test = executable(
  'sdlist_test',
  ['dlist.c'],
  dependencies: [libsaru_list_dep, unity_dep]
)

test('dlist unit tests', sdlist_test)
