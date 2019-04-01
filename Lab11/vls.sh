echo vls
VTOP=./vtop

for i in $VTOP/src/*; do
    echo "**********"
    echo Location: $i
    .  $i/*.state
    echo "File: "$file
    echo "When: "$when
    echo "Locker: "$locker
    echo "Version: "$version
    echo "**********"
done 