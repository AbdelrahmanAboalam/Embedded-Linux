cmd_/home/aboalam/Desktop/Drivers/003_LED/Module.symvers := sed 's/\.ko$$/\.o/' /home/aboalam/Desktop/Drivers/003_LED/modules.order | scripts/mod/modpost -m -a  -o /home/aboalam/Desktop/Drivers/003_LED/Module.symvers -e -i Module.symvers   -T -