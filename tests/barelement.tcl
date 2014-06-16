source base.tcl

set w .bar
set graph [bltBarGraph $w]

$graph element configure data1 -color red -showvalues y 
$graph element configure data2 -color blue

$graph pen create foo -showvalues y -color purple
$graph element activate data3

echo "Testing Bar Element..."

bltTest3 $graph element data3 -activepen foo $dops
bltTest3 $graph element data2 -background yellow $dops
bltTest3 $graph element data2 -barwidth 1 $dops
bltTest3 $graph element data2 -bd 4 $dops
bltTest3 $graph element data2 -bg yellow $dops
bltTest3 $graph element data2 -bindtags {aa} 0
bltTest3 $graph element data2 -borderwidth 4 $dops
bltTest3 $graph element data2 -color yellow $dops
bltTest3 $graph element data1 -data {0.2 8 0.4 20 0.6 31 0.8 41 1.0 50 1.2 59 1.4 65 1.6 70 1.8 75 2.0 85} $dops
bltTest3 $graph element data2 -errorbarcolor green $dops
bltTest3 $graph element data2 -errorbarwidth 2 $dops
bltTest3 $graph element data2 -errorbarcap 10 $dops
bltTest3 $graph element data2 -fg yellow $dops
bltTest3 $graph element data1 -fill cyan $dops
bltTest3 $graph element data2 -foreground green $dops
bltTest3 $graph element data2 -hide yes $dops
bltTest3 $graph element data2 -label "This is a test" $dops
bltTest3 $graph element data2 -legendrelief groove $dops
bltTest3 $graph element data2 -mapx x2 $dops
bltTest3 $graph element data2 -mapy y2 $dops
bltTest3 $graph element data1 -outline red $dops
bltTest3 $graph element data2 -pen foo $dops
bltTest3 $graph element data2 -relief flat $dops
bltTest3 $graph element data2 -showerrorbars no $dops
bltTest3 $graph element data1 -showvalues none $dops
bltTest3 $graph element data1 -showvalues x $dops
bltTest3 $graph element data1 -showvalues both $dops
#bltTest3 $graph element data2 -stack $dops
#bltTest3 $graph element data2 -styles $dops
bltTest3 $graph element data1 -valueanchor nw $dops
bltTest3 $graph element data1 -valueanchor n $dops
bltTest3 $graph element data1 -valueanchor ne $dops
bltTest3 $graph element data1 -valueanchor e $dops
bltTest3 $graph element data1 -valueanchor se $dops
bltTest3 $graph element data1 -valueanchor s $dops
bltTest3 $graph element data1 -valueanchor sw $dops
bltTest3 $graph element data1 -valueanchor w $dops
bltTest3 $graph element data1 -valuecolor cyan $dops
bltTest3 $graph element data1 -valuefont {times 18 bold italic} $dops
bltTest3 $graph element data1 -valueformat "%e" $dops
bltTest3 $graph element data1 -valuerotate 45 $dops
#bltTest3 $graph element data2 -weights $dops
bltTest3 $graph element data1 -x {0 .2 .4 .6 .8 1 1.2 1.4 1.6 1.8} $dops
bltTest3 $graph element data1 -xdata {0 .2 .4 .6 .8 1 1.2 1.4 1.6 1.8} $dops
bltTest3 $graph element data2 -xerror {.1 .1 .1 .1 .1 .1 .1 .1 .1 .1 .1} $dops
#bltTest3 $graph element data2 -xhigh $dops
#bltTest3 $graph element data2 -xlow $dops
bltTest3 $graph element data1 -y {8 20 31 41 50 59 65 70 75 85}  $dops
bltTest3 $graph element data1 -ydata {8 20 31 41 50 59 65 70 75 85} $dops
bltTest3 $graph element data2 -yerror {5 5 5 5 5 5 5 5 5 5 5} $dops
#bltTest3 $graph element data2 -yhigh $dops
#bltTest3 $graph element data2 -ylow $dops

bltCmd $graph element activate data2
bltCmd $graph element deactivate data2
#bltCmd $graph element bind data1 <Button-1> [list puts "%x %y"]
bltCmd $graph element cget data1 -showvalues
bltCmd $graph element configure data1
bltCmd $graph element configure data1 -showvalues
#bltCmd $graph element closest 50 50
#bltCmd $graph element closest 50 50 data1 data2
bltCmd $graph element create data4
bltCmd $graph element create data5
bltCmd $graph element delete data4 data5
bltCmd $graph element exists data1
bltCmd $graph element lower data1
bltCmd $graph element lower data2 data3
bltCmd $graph element names
bltCmd $graph element names data1
bltCmd $graph element raise data2
bltCmd $graph element raise data2 data3
bltCmd $graph element raise data1
bltCmd $graph element show data2
bltCmd $graph element show {data1 data2 data3}
bltCmd $graph element type data1

echo "done"
bltPlotDestroy $w

