# Bash script to parse files

- I make directory called source including many files with diffrent extentions 
and want to parse it according to types (docx,txt,other)
- This is how my dircetory look like befor running script

  ![Screenshot from 2024-07-10 22-02-56](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/ae44f0dd-2ed4-49ac-9808-c344d72cf63a)

-  first part of my script to check if there input to my script

```bash
if [ $# -ne 1 ]; then
echo "Please enter a directoy in command"
exit 1
```
- Second part to make directories that I want move files to it (doc , img , others)

```bash
Source="$1"

mkdir -p "$Source/img" "$Source/others" "$Source/doc" 
```
- Third part is to move files with chossen datatype to new directories

```bash
mv "$Source"/*.jpg "$Source"/*.png "$Source/img" 
mv "$Source"/*.pdf "$Source"/*.docx "$Source"/*.txt "$Source/doc" 
```

- Fourth part to move all files not directories

```bash
for file in "$Source"/*; do
    if [ -f "$file" ]; then
        mv "$file" "$Source/others"
    fi
done
```

After finishing you will see "ALL done"

![Screenshot from 2024-07-10 22-03-39](https://github.com/Aboalam15/Embedded-Linux/assets/159071759/d88aad99-b400-4864-911e-277c8cc4aa95)
