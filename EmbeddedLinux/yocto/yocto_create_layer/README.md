# Creating Layer

- [Create_layer](https://github.com/Aboalam15/Embedded-Linux/blob/main/EmbeddedLinux/yocto/yocto_create_layer/README.md#creating-layer-1)-[Checking_Var_To_Print]()

## Creating layer

```bash
source oe-init-build-env
bitbake-layers create-layer ../meta-Abdo
```
- You will see your lauer out of poky
- under it you will see this

![Screenshot from 2024-08-07 01-00-52](https://github.com/user-attachments/assets/2230fdd9-0c39-48d7-aed2-c8b18f065962)
- Now we will check th configs from conf/local.conf

![Screenshot from 2024-08-07 01-04-40](https://github.com/user-attachments/assets/029805dd-1777-4abd-a959-eab02d4a208a)

- Now we will make our recipe
```bash
mkdir my_recipe
cd my_recipe
touch Aboalam_0.2.bb
touch Aboalam_0.2.bbappend
nano Aboalam_0.2.bb
```
```python
SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Aboalam created a Reicpe"
LICENSE = "CLOSED"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Welcome To Recipe By Abdelrahman Aboalam   *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
```
- Now we want to add our layer to bblayers

![Screenshot from 2024-08-07 01-18-19](https://github.com/user-attachments/assets/f035420b-9825-4ebf-943d-43591d3ffc5a)

- You can check layers by
```bash
bitbake-layers show-layers
```
![Screenshot from 2024-08-06 16-52-53](https://github.com/user-attachments/assets/bb06f4ca-e3c4-4d65-9f3a-cdea8edacc55)


- Now we can run it
```bash
bitbake Aboalam
```
![Screenshot from 2024-08-06 17-24-52](https://github.com/user-attachments/assets/300fd710-8e4b-4ea4-b171-08cc5dcc354f)


## Checking Variable

- First we will add variable under our recipe in meta-Abdo/conf/layer.conf

![Screenshot from 2024-08-07 01-28-05](https://github.com/user-attachments/assets/cf768c0e-05a8-4948-b438-c54006094a72)

- Now we will write our code under meta-Abdo/recipes/my_recipe/Aboalam_0.2.bbappend

```python
# Aboalam_0.2.bbappend

python __anonymous() {
    var_value = d.getVar('MY_CUSTOM_VAR')
    if var_value == "3":
        d.appendVar('do_display_banner', '\n    bb.plain("Aboalam var 3")\n')
    elif var_value == "4":
        d.appendVar('do_display_banner', '\n    bb.plain("Aboalam var 4")\n')
}
```

- Now we will run our recipe and we will show result
```bash
bitbake Aboalam
```

![Screenshot from 2024-08-06 17-47-06](https://github.com/user-attachments/assets/16c657a9-c4e9-4de4-b210-58cbb45d67ba)

