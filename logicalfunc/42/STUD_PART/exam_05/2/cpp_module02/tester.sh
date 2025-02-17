# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfregni <tfregni@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2023/11/05 00:51:20 by tfregni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN='main.cpp'
MAIN1='cpp_module02/main.cpp'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/grading
clang++ -Wall -Wextra -Werror -std=c++98 -o source Warlock.cpp ASpell.cpp ATarget.cpp BrickWall.cpp Dummy.cpp Fireball.cpp Fwoosh.cpp Polymorph.cpp SpellBook.cpp TargetGenerator.cpp $MAIN
./source | cat -e > sourcexam       #TESTING
rm source
cp main.cpp ../../rendu/cpp_module02
cd ../../rendu
{
clang++ -Wall -Wextra -Werror -std=c++98 -o final cpp_module02/Warlock.cpp cpp_module02/ASpell.cpp cpp_module02/ATarget.cpp cpp_module02/BrickWall.cpp cpp_module02/Dummy.cpp cpp_module02/Fireball.cpp cpp_module02/Fwoosh.cpp cpp_module02/Polymorph.cpp cpp_module02/SpellBook.cpp cpp_module02/TargetGenerator.cpp $MAIN1
}  &>../.system/grading/traceback
rm -f cpp_module01/main.cpp
# if there is a traceback file, exit this script
# if [ -e ../.system/grading/traceback ]
# then
# 	mv ../.system/grading/traceback ../traceback
# 	exit 1
# fi
{
./final | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
rm final
}  &>/dev/null
cd ../.system/grading
DIFF=$(diff sourcexam finalexam)
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
		cat sourcexam >> traceback
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		echo "<--------------~-~-~-~-~-~-~-~-~------------>\n\n" >> traceback
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
fi
rm finalexam

if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
