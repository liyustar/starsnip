#!/bin/bash

git config --global user.name "liyustar"
git config --global user.email "liyustar@gmail.com"
git config --global color.ui true
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch
# git config --global push.default matching
# git config --global push.default simple
# git config --global core.editor "mate -w" # set editor use textmate
git config -l # list all config
