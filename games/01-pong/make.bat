set compile_folder=%cd%\compile

if not exist %compile_folder% mkdir %compile_folder%

for /f %%i in ('dir /b /s *.c') do (
    c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o "%compile_folder%\%%~ni.o" "%%~fi"
)

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o %compile_folder%\game.gb %compile_folder%\main.o %compile_folder%\screen.o %compile_folder%\move.o %compile_folder%\render.o %compile_folder%\Ship.o

move %compile_folder%\game.gb %cd%\game.gb

rmdir /s /q  %compile_folder%