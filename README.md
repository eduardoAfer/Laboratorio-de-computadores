# Laboratorio-de-computadores
Project in C language that works on ppm pictures



ppm_h_flip which flips a ppm image 180º horizontally

Synopse

$ ppm_h_flip [input.ppm [output.ppm]]
Use examples

<pre><code>$ ./ppm_h_flip < input.ppm > output.ppm
$ ./ppm_h_flip input.ppm > output.ppm
$ ./ppm_h_flip input.ppm output.ppm</code></pre>
ppm_v_flip which flips a ppm image 180º verticall

Synopse:

$ ppm_v_flip [input.ppm [output.ppm]]
Use examples:

$ ./ppm_v_flip < input.ppm > output.ppm
$ ./ppm_v_flip input.ppm > output.ppm
$ ./ppm_v_flip input.ppm output.ppm
ppm_d_flip which flips a ppm image diagonally (from top-left to low-right)

Synopse

$ ppm_d_flip [input.ppm [output.ppm]]
Use examples:

$ ./ppm_d_flip < input.ppm > output.ppm
$ ./ppm_d_flip input.ppm > output.ppm
$ ./ppm_d_flip input.ppm output.ppm
ppm_addRGB which adjusts the RGB components of the ppm image

Ajusts the RGB components according to the arguments given at launch. For the adjustment triplet (dR, dG, dB), the colour values of each pixel i become (Ri + dR, Gi + dG, Bi + dB)
Synopse:

$ ppm_addRGB dR dG dB [input.ppm [output.ppm]]
Use examples:

$ ./ppm_addRGB +10 -1 +50 < input.ppm > output.ppm
$ ./ppm_addRGB -20 +30 0 input.ppm > output.ppm
$ ./ppm_addRGB 0 0 +100 input.ppm output.ppm
ppm_grayscale which generates a grayscale version of a ppm image

The value of each pixel (R,G,B) becomes (G,G,G), where G = 0.2126R + 0.7152G + 0.0722B
Synopse:

$ ppm_grayscale [input.ppm [output.ppm]]
Use examples:

$ ./ppm_grayscale < input.ppm > output.ppm
$ ./ppm_grayscale input.ppm > output.ppm
$ ./ppm_grayscale input.ppm output.ppm
ppm_bw which generates a black and white version ppm image, according to a color threshold

The value of each pixel (R,G,B) i becomes (MAXCOLOR,MAXCOLOR,MAXCOLOR), if grayscale value of i, G > threshold. (0,0,0) if otherwise.
Synopse:

$ ppm_bw threshold [input.ppm [output.ppm]]
where 0 < threshold < MAXCOLOR
Use examples:

$ ./ppm_bw 64 < input.ppm > output.ppm
$ ./ppm_bw 77 input.ppm > output.ppm
$ ./ppm_bw 100 input.ppm output.ppm
ppm_rot_right which rotates a ppm image by 90º to the right

Synopse:

$ ppm_rot_right [input.ppm [output.ppm]]
Use examples:

$ ./ppm_rot_right < input.ppm > output.ppm
$ ./ppm_rot_right input.ppm > output.ppm
$ ./ppm_rot_right input.ppm output.ppm
ppm_rot_left which rotates a ppm image by 90º to the left

Synopse

$ ppm_rot_left [input.ppm [output.ppm]]
Use examples

$ ./ppm_rot_left < input.ppm > output.ppm
$ ./ppm_rot_left input.ppm > output.ppm
$ ./ppm_rot_left input.ppm output.ppm
ppm_addBorder which adds a frame to a ppm image

Synopse:

$ $ ./ppm_addBorder width R G B [input.ppm [output.ppm]]
Use examples:

$ ./ppm_addBorder width R G B < input.ppm > output.ppm
$ ./ppm_addBorder width R G B input.ppm > output.ppm
$ ./ppm_addBorder width R G B input.ppm output.ppm
Compile

Make is used for compilation:

make hflip # generates ppm_h_flip
make vflip # generates ppm_v_flip
make dflip # generates ppm_d_flip
make addrgb # generates addRGB
make grayscale # generates ppm_grayscale
make blackwhite # generates ppm_bw
make rotright # generates ppm_rot_right
make rotleft # generates ppm_rot_left
make frame # generates ppm_addBorder
make all # generates all programs
Excutables will be placed in bin/
