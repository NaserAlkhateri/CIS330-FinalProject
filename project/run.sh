read -p "- To play vs computer enter (1)
- To play vs player   enter (2)
- To make clean       enter (3)
" make
case "$make" in
    1) make manhunt.exe
	   ./manhunt.exe;;
    3) make clean ;;
    *) echo "Wrong choice " ;;
esac
