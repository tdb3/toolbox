# Python venv example

Install venv

    apt install python3-venv
    
Run venv to create a new virtual environment

    python3 -m venv newprojectdir
    cd newprojectdir

Activate the virtual environment

    source bin/activate
    
When activating a virtual environment, PATH is updated to prefer our new project.

Install dependencies for project (as needed)

    pip install -r requirements.txt
    
Create requirements.txt

    pip freeze > requirements.txt

To deactivate the venv:

    deactivate

To delete the venv:

    deactivate
    cd ..
    rm -rf newprojectdir
    
