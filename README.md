# audconk
Audconk is for use with conky audacious-qt5 and audacious-qt5-plugins, and provides the album artwork for conky to display on your desktop.

It assumes your artwork is a single jpg file stored in the album folder of your music library, as in: "/radiohead/ok_computer/folder.jpg."
The program generates files in the ~.local/share/conkydacious directory, which conky uses to display the contents.  Here is a list of files this
program produces and places in that directory:

folder.jpg (artwork image)
currartsize.txt (size in bytes of artwork)

Once installed, you will need to first create a directory, (1) mkdir ~.local/share/conkydacious, then (2) enable the Song Change plugin,
in Audacious. Under the plugin's first command field: "Command to run when starting a new song:", enter the path and command
for this program. You can then use the sample .conkyrc to modify conky to display the result. Note, a track 
must be started to activiate this program and therefore provide the files to conky.

Here are sample conky lines you can tailor for your conky install and the audtool utility (for audacious-qt5) so tag information and artwork can be diplayed in conky:

<br>${exec audtool --current-song-tuple-data artist | fold -s -w 62} - ${color Grey}${font Terminus:size=8}</br>
<br>${exec audtool --current-song-tuple-data album | fold -s -w 62}</br>
<br>(${exec audtool --current-song-tuple-data year})</br>
<br>${font Terminus:size=8:bold}${color 0077ff}${exec audtool --current-song-tuple-data title | fold -s -w 62}</br>
<br>${color Grey}${font Terminus:size=8}Time: ${exec audtool --current-song-output-length}/${exec audtool --current-song-length}</br>
<br>Bitrate:${exec audtool --current-song-bitrate-kbps} Rating code:${exec cat ~/.local/share/conkydacious/currgpnum.txt}</br>
<br>Art Size:${exec cat ~/.local/share/conkydacious/currartsize.txt}</br>
<br>${color Grey}${font Terminus:size=7}${exec audtool --current-song-tuple-data comment | fold -s -w 69 | head -n 8}</br>
<br>${image ~/.local/share/conkydacious/folder.jpg -p 0,388 -s 250x250 -n -f1}</br>


See Conky sample script (sample .conkyrc file) in docs folder for full example. (Includes other script data, and you will need to adapt coordinates for your arrangement. The sample was written for a dual monitor setup. It will likely not work for you 'as is'.)

