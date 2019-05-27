# c---sierpinski-fractal-recursively
glut setup step
1 - copy glut32.dll file and paste it into your system folder.If you have a 32 bits operating system, place glut32.dll to C:\Windows\System32\, if your operating system is 64 bits, place it to 'C:\Windows\SysWOW64\'
2 - copy glut.h file and paste it to C:\Program Files (x86)\CodeBlocks\MinGW\include\GL
3 - copy libglut32.a file and paste it to C:\Program Files (x86)\CodeBlocks\MinGW\lib
4 - open settings-compiler-Linker settings
5 - add libglu32.a , libglut32.a , libopengl32.a files from C:\Program Files (x86)\CodeBlocks\MinGW\lib
