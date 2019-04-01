echo "valloc"

VTOP=./vtop
VTOP_ETC="$VTOP/etc" 
VTOP_SRC="$VTOP/src" 

if [ -d "$VTOP" ]; then
echo "$VTOP Found"
exit 1
else
mkdir -p $VTOP
echo "$VTOP directory created"
mkdir $VTOP_ETC
echo "$VTOP_ETC directory created"
mkdir $VTOP_SRC
echo "$VTOP_SRC directory created"
fi
exit 1
