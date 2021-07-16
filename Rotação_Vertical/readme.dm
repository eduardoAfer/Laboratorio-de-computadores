Pretende-se que implemente um programa em C que faça uma rotação vertical (rotação de 180 graus em torno de um eixo horizontal) de uma imagem em formato PPM. A imagem poderá ser lida da entrada padrão ou de um ficheiro de input (caso seja especificado na linha de comandos). A imagem transformada deverá ser enviada para a saída padrão, ou então, para um ficheiro de output (caso seja especificado na linha de comandos). O ficheiro PPM de output deverá conter apenas um pixel por linha, e não deverá ter comentários.

Nota: Caso não seja possível abrir o(s) ficheiro(s), deverá ser gerada uma mensagem de erro adequada.

Sinopse (assumindo que a aplicação desenvolvida se chama ppm_v_flip):

$ ./ppm_v_flip [input.ppm [output.ppm]]
Exemplos de invocação do aplicativo:

$ ./ppm_v_flip < input.ppm > output.ppm
$ ./ppm_v_flip input.ppm > output.ppm
$ ./ppm_v_flip input.ppm output.ppm
Exemplo de execução 1:

Considere o ficheiro img.ppm:

  Ficheiro img.ppm (ampliado)

A execução do programa:

$ ./ppm_v_flip img.ppm img_vflipped.ppm
deverá gerar o ficheiro img_vflipped.ppm:

 

Ficheiro img_vflipped.ppm (ampliado)
Ficheiro img_vflipped.ppm (ampliado)
cujo conteúdo é:

P3
3 2
255
255 255 0
255 255 255
0 0 0
255 0 0
0 255 0
0 0 255 
Exemplo de execução 2:

Considere o ficheiro matisse.ppm:

matisse.ppm
matisse.ppm
A execução do programa:

$ ./ppm_h_flip < matisse.ppm > matisse_hflipped.ppm
deverá gerar o ficheiro matisse_vflipped.ppm:

 

matisse_vflipped.ppm
matisse_vflipped.ppm