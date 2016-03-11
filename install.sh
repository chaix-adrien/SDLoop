#!/bin/sh
clear
echo "Installing SDLoop by Adrien Chaix\n"

get_out()
{
    echo $1
    exit
}

test_and_add_bash()
{
    if [ -e $1 ] ; then
	echo "" >> $1
	echo "export LD_LIBRARY_PATH=\"/home/${USER}/.froot/lib/\"" >> $1
	echo "export C_INCLUDE_PATH=\"/home/${USER}/.froot/include/\"" >> $1
	echo "export CPLUS_INCLUDE_PATH=\"/home/${USER}/.froot/include/\"" >> $1
    fi
}

test_and_add_csh()
{
    if [ -e $1 ] ; then
	echo "" >> $1
	echo "setenv LD_LIBRARY_PATH \"/home/${USER}/.froot/lib/\"" >> $1
	echo "setenv C_INCLUDE_PATH \"/home/${USER}/.froot/include/\"" >> $1
	echo "setenv CPLUS_INCLUDE_PATH \"/home/${USER}/.froot/include/\"" >> $1
    fi
}

echo "Installing SDL, plean enter Root psw for apt-get"
sudo apt-get install libsdl1.2-dev libsdl-ttf2.0-dev libsdl-image1.2-dev\
    libsdl-mixer1.2-dev libsdl-mixer1.2 || get_out "Failed to install SDL"

echo "\nTargets are ~/.froot/include and ~/.froot/lib"
mkdir -p ~/.froot/lib ~/.froot/include	|| get_out "Failed to create installation directories."

rm -f ~/.froot/include/sdloop.h ~/.froot/include/sdloop_private.h \
   ~/.froot/include/sdloop_define.h ~/.froot/lib/libsdloop.a

cp include/*.h ~/.froot/include/	|| get_out "Failed to install Lapin headers."
make re					|| get_out "No files were build. Make failed."
make clean

chmod 644 ~/.froot/include/*.h*		|| get_out "Failed to change mode of headers."
chmod 644 ~/.froot/include/*/*.h*	|| get_out "Failed to change mode of headers."
chmod 644 ~/.froot/lib/*.a		|| get_out "Failed to change mode of binaries."

echo "Adding variables to your shell configuration. Do not forget to restart it after."

test_and_add_bash ~/.shrc
test_and_add_bash ~/.bashrc
test_and_add_bash ~/.kshrc
test_and_add_bash ~/.zshrc

test_and_add_csh ~/.cshrc
test_and_add_csh ~/.tcshrc

get_out "\n\nInstalation : OK!\n"
