if [ $# -lt 3 ]
then
echo "insufficient arguments"
exit 1
else
sed -n "$1,$2p" $3
fi
