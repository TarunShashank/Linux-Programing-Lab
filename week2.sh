if [ $# -eq 0 ]
then
echo "insufficient args"
else
echo "enter word"
read word
for i in $*
do
if [ -f $i ]
then
echo "the word $word is deleted from $i"
echo "the $i contents after $word delete"
grep -v $word $i
else 
echo "$i is not a file"
fi
done
fi
