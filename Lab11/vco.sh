echo "vco"



while getopts "l:" opt; do
  case ${opt} in
    l ) 

      . $VTOP/src/$2/$2.state
        echo "Option -l"
        echo $locker
        echo whoami
        if [ ! "$locker" = "$(whoami)" ]; then
          echo "No permission"
          exit 
        else
          n=$version
          cp $VTOP/src/$2/$2.$n $2
          echo "Copy of file created"
          chmod 666 $2
          echo "Changed permissions"
          exit 
        fi
      ;;
    \? ) echo "Usage: cmd [-l] <fileName>"
      ;;
  esac
  
done

for i in "$@"
do
    if [ -r $i ]; then
        echo "$i Already exists"
        exit
    fi

    . $VTOP/src/$i/$i.state

    if [ -e "$VTOP/src/$i" ]; then
        echo "File found in src"
        n=$version
        ln $VTOP/src/$i/$i.$n $i
        echo "Created a link"

    else
        echo "File not found in src"
    fi 
done 