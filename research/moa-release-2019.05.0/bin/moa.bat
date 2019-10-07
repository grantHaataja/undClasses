@echo off

set BASEDIR=%~dp0\..
set MEMORY=512m

java -Xmx%MEMORY% -cp "%BASEDIR%/lib/moa-2019.05.0;%BASEDIR%/lib/*" -javaagent:%BASEDIR%/lib/sizeofag-1.0.4.jar moa.gui.GUI

