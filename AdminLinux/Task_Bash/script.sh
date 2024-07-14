if [ $# -ne 1 ]; then

echo "Please enter a directoy in command"
exit 1

fi



Source="$1"

mkdir -p "$Source/img" "$Source/others" "$Source/doc" 

mv "$Source"/*.jpg "$Source"/*.png "$Source/img" 
mv "$Source"/*.pdf "$Source"/*.docx "$Source"/*.txt "$Source/doc"

for file in "$Source"/*; do
    if [ -f "$file" ]; then
        mv "$file" "$Source/others"
    fi
done
echo All done
# mv "$Source"/* "$Source/others"
