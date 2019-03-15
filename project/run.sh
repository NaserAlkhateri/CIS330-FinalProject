read -p "- To play vs computer enter (1)
- To play vs player   enter (2)
- To make clean       enter (3)
- To check memory leak for PVC enter (4)
- To check memory leak for PVP enter (5)
" make
case "$make" in
    1) make manhunt.exe
	   ./manhunt.exe;;
	2) make manhuntPvP.exe
	   ./manhuntPvP.exe;;
    3) make clean ;;
	4) make memcheckManhunt.exe ;;
	5) make memcheckManhuntPvP.exe ;;
    *) echo "Wrong choice " ;;
esac
