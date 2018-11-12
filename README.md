# audconk
Audconk is for use with conky audacious-qt5 and audacious-qt5-plugins, and provides mp3 tag info and artwork to your DE via conky.

Once installed, you will need to first create a directory, (1) mkdir ~.local/share/conkydacious, then (2) enable the Song Change plugin,
in Audacious. Under the plugin's first command field: "Command to run when starting a new song:", enter the path and command
for this program. You can then use the sample .conkyrc to modify conky to display the result. Note, a track 
must be started to activiate this program and therefore activate conky.

See Conky sample script (sample .conkyrc file). You will need to adapt coordinates for your arrangement. The sample was written for a dual monitor setup.

