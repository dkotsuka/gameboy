@echo off
setlocal enabledelayedexpansion

rem Define a pasta de compilação como um subdiretório "compile" no diretório atual
set compile_folder=%cd%\compile

rem Cria a pasta de compilação se ela não existir
if not exist %compile_folder% mkdir %compile_folder%

rem Compila todos os arquivos .c na pasta atual e subdiretórios
for /f %%i in ('dir /b /s *.c') do (
    rem Compila cada arquivo .c para um arquivo .o na pasta de compilação
    c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o "%compile_folder%\%%~ni.o" "%%~fi"
)

rem Inicializa a variável "file" com o caminho para o arquivo de saída do jogo
set file=%compile_folder%\game.gb

rem Adiciona todos os arquivos .o da pasta de compilação à variável "file"
for /f %%i in ('dir /b /s "%compile_folder%\*.o"') do (
    rem Concatena o caminho completo de cada arquivo .o à variável "file"
    set "file=!file! %%~fi"
)

rem Linka todos os arquivos .o e gera o arquivo final .gb (ROM do Game Boy)
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o %file%

rem Move o arquivo final .gb da pasta de compilação para o diretório atual
move %compile_folder%\game.gb %cd%\game.gb

rem Remove a pasta de compilação e todo o seu conteúdo
rmdir /s /q %compile_folder%

endlocal