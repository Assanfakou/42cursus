#!/bin/bash

mkdir ~/bin 2>/dev/null
cd ~/bin
curl https://imagemagick.org/archive/binaries/magick -o magick.image
chmod a+x magick.image
./magick.image --appimage-extract > /dev/null
mv squashfs-root magick_bin > /dev/null
echo "alias magick=$HOME/bin/magick_bin/AppRun" >> ~/.zshrc
zsh
echo -n "Done 👽\n\n"
sleep 1
echo "Usage: magick alien.png alien.xpm"
cd -
