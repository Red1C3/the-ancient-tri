project('the-ancient-tri','cpp')
fs=import('fs')
if host_machine.system()=='linux'
    pkgconfig=import('pkgconfig')
endif
sfmlWindow=dependency('sfml-window')
sfmlGraphics=dependency('sfml-graphics')
glbinding=dependency('glbinding')
assimp=dependency('assimp')
inc_dir=include_directories('include')
srcAssembler=run_command('srcAssembler.sh')
sources=srcAssembler.stdout().strip().split('\n')
main='./main.cpp'
if fs.exists(main)
    executable('the-ancient-tri',sources+['main.cpp'],include_directories:[inc_dir],dependencies:[sfmlWindow,glbinding,assimp,sfmlGraphics])
endif
lib=library('the-ancient-tri',sources,include_directories:[inc_dir],dependencies:[sfmlWindow,glbinding,assimp,sfmlGraphics])
if host_machine.system()=='linux'
    pkgconfig.generate(lib)
endif