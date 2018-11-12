# audconk
Audconk is for use with conky audacious-qt5, and provides mp3 tag info and artwork to your DE via conky.

Once installed, you will need to first create a directory, (1) mkdir ~.local/share/conkydacious, (2) then enable the Song Change plugin,
in Audacious. Under the plugin's first command field: "Command to run when starting a new song:", enter the path and command
for this program. You can then use the below sample .conkyrc code to modify conky to display the result. Note, a track 
must be started to activiate this program and therefore activate conky.

Conky sample script (note this is not a full .conkyrc file, just the audacious portion). You will need to adapt the 
coordinates for your arrangement. The one here was written for a dual monitor setup.


[code]${font Terminus:size=8:bold}${color 0077ff}${exec audtool --current-song-tuple-data artist | fold -s -w 62} - ${color Grey}${font Terminus:size=8}${exec audtool --current-song-tuple-data album | fold -s -w 62} (${exec audtool --current-song-tuple-data year})      









[THIS IS INTENTIONAL SPACE FOR COVER ART]








${font Terminus:size=8:bold}${color 0077ff}${exec audtool --current-song-tuple-data title | fold -s -w 62}
${color Grey}${font Terminus:size=8}Time: ${exec audtool --current-song-output-length}/${exec audtool --current-song-length}   Bitrate:${exec audtool --current-song-bitrate-kbps} Rating code:${exec cat ~/.local/share/conkydacious/currgpnum.txt} Art Size:${exec cat ~/.local/share/conkydacious/currartsize.txt} 
${color Grey}${font Terminus:size=8}Playlist: ${exec audtool --playlist-position} of ${exec audtool --playlist-length} Last played: ${exec cat ~/.local/share/conkydacious//lastplayed.txt}
${color Grey}${font Terminus:size=7}${exec audtool --current-song-tuple-data comment | fold -s -w 69 | head -n 8}
$hr
${font Terminus:size=8:bold}${color 0077ff}Date & Time ${color}
${color grey}${time %e %B %Y   %A    %I:%M %p}
$hr
${image ~/.local/share/conkydacious/folder.jpg -p 0,388 -s 250x250 -n -f1}
${image ~/.local/share/conkydacious/starrating.png -p 235,664 -s 100x20 -n -f1}[/code]
