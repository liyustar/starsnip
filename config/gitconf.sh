#!/bin/bash

git config --global user.name "liyustar"
git config --global user.email "liyustar@gmail.com"

git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

git config --global color.ui true
git config --global core.editor vim
git config --global core.autocrlf false
git config --global core.safecrlf true

git config --global push.default simple

git config -l # list all config
