#########################################################################
# File Name: test.sh
# Author: liyuxing
# mail: liyustar@gmail.com
# Created Time: 2013年10月06日 星期日 12时51分45秒
#########################################################################
#!/bin/bash

SOURCELIST=/etc/apt/sources.list
UBUNTU_CODE_12_04=precise
UBUNTU_CODE_NOW=raring

if [ ! -e $SOURCELIST.bk ]; then
	mv $SOURCELIST $SOURCELIST.bk
	sed "s/$UBUNTU_CODE_12_04/$UBUNTU_CODE_NOW/" ./source_list.t > $SOURCELIST
	apt-get update
	echo "star -- updata sources list done!"
fi

echo "star -- install vim"
apt-get install vim
echo "star -- install git"
apt-get install git

apt-get install tree

#sudo apt-get
