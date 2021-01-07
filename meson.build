project('lhc-generator', ['cpp', 'c'],
  version: '0.1.0',
  default_options: ['cpp_std=c++17'])

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')
m_dep = cc.find_library('m', required : false)

## Compiler optimization
compiler_flags = []
linker_flags = []
if cc.get_id() == 'gcc'
	compiler_flags += ['-march=native', '-flto', '-funsafe-loop-optimizations']
	linker_flags += ['-flto']
	add_global_link_arguments(['-flto'], language: 'c')
	add_global_link_arguments(['-flto'], language: 'cpp')
elif cc.get_id() == 'clang'
	compiler_flags += ['-march=native', '-flto=thin']
	linker_flags += ['-flto=thin']
endif
add_global_arguments(compiler_flags, language: 'c')
add_global_link_arguments(linker_flags, language: 'c')
add_global_arguments(compiler_flags, language: 'cpp')
add_global_link_arguments(linker_flags, language: 'cpp')

abseil_proj = subproject('abseil')
abseil_random_dep = abseil_proj.get_variable('absl_random_dep')
abseil_strings_dep = abseil_proj.get_variable('absl_strings_dep')
abseil_time_dep = abseil_proj.get_variable('absl_time_dep')

fmt_proj = subproject('fmt')
fmt_dep = fmt_proj.get_variable('fmt_dep')

spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')

executable('lhc-generator', 
           ['lhc-generator.cc'],
           dependencies: [m_dep, abseil_random_dep, abseil_strings_dep, abseil_time_dep, fmt_dep, spdlog_dep])
