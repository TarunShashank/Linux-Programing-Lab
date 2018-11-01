if [ $# -eq 0 ]
then
echo "Insufficient Arguments"
exit 1;
fi
fact=1
n=$1
num=$n
while [ $num -ge 1 ]
do
fact=`expr $fact \* $num`
num=`expr $num - 1`
done
echo "The factorial of $n is $fact"
