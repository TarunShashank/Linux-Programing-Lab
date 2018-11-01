BEGIN{print "record\tcharacter\twords"}
{
len=length($0)
total_len+=len
print(NR,":\t",len,":\t",NF,$o)
words+=NF
}
END{
print("\n total")
print("character :\t"total_len)
print("lines :\t"NR)
print("word :\t"words)
}
