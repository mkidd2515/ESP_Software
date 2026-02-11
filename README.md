# Install & Configuration 

### Important Dependancies:
- python3
- git
- pip
- pyenv
- pyenv-virtualenv
- mercurial
- arm-none-eabi-{gcc,gdb,binutils,newlib}

## Step-by-step

- Install all dependancies via your package manager (we'll be assuming an Arch Linux environment).

- Add the lines below into your `.bashrc` and `.bash_profile` 
```
export PYENV_ROOT="$HOME/.pyenv"
[[ -d $PYENV_ROOT/bin ]] && export
PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init - bash)"
eval "$(pyenv virtualenv-init - bash)"
```

- After you get all the dependencies set up, clone this repository and go into the directory. 

- Install python version `3.11.9` (or lower) using the command `pyenv install 3.11.9` 

- Create a virtual environment with the command `pyenv virtualenv mbed-env` which'll use the python version we installed with pyenv (assuming you haven't other versions installed).  

- Activate the new python virtual environment w/ cmd `pyenv activate mbed-env`

- Set-up the repo dir to be managed by the aforemade env by the cmd `pyenv local mbed-env`

- Test that this is working by typing `python --version`. You should see `3.11.9` or whatever version you installed.

- Install mbed-cli via `python -m pip install mbed-cli`

- Test that it is working by typing `mbed`

- Create a new mbed project using mbed-cli via the cmd `mbed new .`

- Check that your mbed-os version is correct by running `mbed ls` 

- Set compilation target of project with the cmd `mbed target NUCLEO_F401RE`

- Set toolchain using cmd `mbed toolchain GCC_ARM`

- Compile the libraries with `mbed compile` (this'll take a minute)

- You're now ready to start programming!

## References: 
- [Official MBed CLI1 Set Up Guide](https://os.mbed.com/docs/mbed-os/v6.16/build-tools/install-and-set-up.html)
- Arduous trial and error mostly
