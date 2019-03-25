echo vci

VTOP=./vtop

for i in "$@"
do
    if [ -r $i ]; then
        echo "$i exists and is readable"
        if [ ! -e $VTOP/src/$i ]; then
            mkdir $VTOP/src/$i 
            echo "$i created file directory"
        fi

        if [ ! -e $VTOP/src/$i/$i.state ]; then
            touch "$VTOP/src/$i/$i.state"
            echo "file=$i" >> "$VTOP/src/$i/$i.state"
            echo "when="\'$(date)\' >> "$VTOP/src/$i/$i.state"
            echo "locker="$(whoami) >> "$VTOP/src/$i/$i.state"
            echo "version=1" >> "$VTOP/src/$i/$i.state"
            echo "Added state file"
            cp $i $VTOP/src/$i
            echo "Copied file"
            chmod 444 $VTOP/src/$i/$i
            echo "Changed new file permission to read only"
            echo "File checked in Successfully"
        else
            . $VTOP/src/$i/$i.state
            n=$version
            n=$[$n + 1]
            echo "file=$i" > "$VTOP/src/$i/$i.state"
            echo "when="\'$(date)\' >> "$VTOP/src/$i/$i.state"
            echo "locker="$(whoami) >> "$VTOP/src/$i/$i.state"
            echo "version=$n" >> "$VTOP/src/$i/$i.state"
            cp $i $VTOP/src/$i/$i.$n
            echo "Copied file"
            chmod 444 $VTOP/src/$i/$i.$n
            echo "Changed new file permission to read only"
            echo "Updated state file"
            echo "File checked in Successfully"
        fi
    else
        echo "$i does not exist or is not redable"
    fi
done 


