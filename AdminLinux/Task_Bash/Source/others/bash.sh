# for i in {1..9};do
# echo Abdelrahmn
# done

# x=0
# y=10
# while [[ $x -le 6 && $y -ge 0 ]];do
# echo "x=$x"
# echo "y=$y"
# ((x++))
# ((y++))
# done

# cities=("New Yourk" "Los ANGLOUS")
# cities[2]="ITI"
# echo "Cities : ${cities[@]}"


# cities=("New Yourk" "Los ANGLOUS")
# cities[2]="ITI"
# echo "Cities : ${cities[*]}"

# cities=("New Yourk" "Los ANGLOUS")
# cities[2]="ITI"
# for var in ${cities[@]}
# do
# echo "$var"
# done

# cities=("New Yourk" "Los ANGLOUS")
# cities[2]="ITI"
# for var in "${cities[@]}"
# do
# echo "$var"
# done


# cities=("New Yourk" "Los ANGLOUS")
# cities[2]="ITI"
# for var in "${cities[*]}"
# do
# echo "$var"
# done

# cities=("New Yourk" "Los ANGLOUS")
# cities[2]="ITI"
# for var in "${cities[@]:1:3}"
# do
# echo "$var"
# done

##################################################### unset to delet array  (unset citiy[0]) ##########################################

# declare -A country

# country[USA]="New York"
# country[Egy]="Menouf"
# country[Mag]="Moraco"
# country[Ger]="Berlin"

# for var in "${country[@]}"
# do
# echo "$var"
# done

# echo after delete
# unset country[Mag]

# for var in "${country[@]}"
# do
# echo "$var"
# done


# cities=("Octobar" "Zaied" "Menof" "Cairo" "Tanta")

# echo ${cities[0]}
# echo ${cities[1]}
# echo ${cities[2]}
# echo ${cities[3]}
# echo ${cities[4]}
# echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++"

# echo "The length of Array is ${#cities[@]}"



# for var in "${cities[@]}"
# do
# echo "$var"
# done


###############################################################

# echo "Script name: $0"
# echo "Total number of arguments: $#"

# for arg in "$@";do
# echo "- $arg"
# done

# echo "All arguments (together): $*"

# if [ $# -ge 1 ]; then
# echo "First argu: $1"
# fi 

# if [ $# -ge 2 ]; then
# echo "Seconde argu: $1"
# fi 

# ls

# if [ $? -eq 0 ]; then
# echo "All good"
# else
# echo "error $?"
# fi

###############################################################

# read -p "Enter  " choice 

# case $choice in
# "1"|1)
# echo "1111"
# ;;
# "2")
# echo "22222"
# ;;
# *) 
# echo "Error Ya m3alem"
# ;;
# esac


# select color in red green blue orange
# do
# echo  "Choose : $color"
# break
# done
####################################################################

# PS3="Enter your Choice"
# select Lab in "Display data and time" "List file in crunet directory" "Display crunet Disk usage" "Exit"
# do
# case $Lab in
# "Display data and time")
# date 
# ;;
# "List file in crunet directory")
# ls
# ;;

# "Display crunet Disk usage")
# df -h
# ;;
# "Exit")
# echo "Good Byeeeeeeeeeeeeeeee"
# ;;

# *)

# ;;
# esac
# break
# done

##########################################################################

# DisplayArg ()
# {
#     echo $1 $2 $3
# }

# DisplayArg "Abdelrahman" "Aboalam" "Ahmed" "Zakria"

# DisplayArg $1 "Abdelrahman"

if [ $# -ne 1 ]; then

echo "Usage: $0<Source>"
exit 1

fi

echo hello

Source="$1"

makdir -p "$Source/img" "$Source/others" "$Source/doc" 

mv "$Source"/*.jpg "$Source"/*.png "$Source/img"
mv "$Source"/*.pdf "$Source"/*.doc "$Source"/*.text "$Source/doc"
mv "$Source"/* "$Source/others"