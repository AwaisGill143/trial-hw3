# GitHub Setup

- [GitHub Setup](#github-setup)
  - [Windows](#windows)
    - [`Windows PowerShell`](#windows-powershell)
    - [Installing `git`](#installing-git)
    - [Configuring `git`](#configuring-git)
    - [SSH Key Generation](#ssh-key-generation)
    - [Configure SSH agent](#configure-ssh-agent)
    - [Adding key to `GitHub`](#adding-key-to-github)
    - [Cloning the homework repository](#cloning-the-homework-repository)

## Windows

### `Windows PowerShell`

Run `Windows PowerShell` as administrator.

### Installing `git`

Run the following command to check if git is installed.

```bash
git --version
```

If git is not installed, install it from [Git - Download](https://git-scm.com/downloads/win).

### Configuring `git`

After successful installation, run the following commands in `Windows Powershell`

```bash
git config --global user.name "firstname lastname"
git config --global user.email "gitHub-email-id"
```

### SSH Key Generation

In order to generate SSH key to add in your GitHub, run the following commands in `Windows Powershell`

```bash
ssh-keygen -t rsa -b 4096 -C "gitHub-email-id"
```

You will be prompted to enter the filename; press `Enter`. Next, to enter the passphrase, press `Enter`. You will then be asked to confirm the passphrase by entering it again; press Enter to complete.

### Configure SSH agent

The following commands configure the SSH agent to start automatically, activate the SSH agent service, add a private SSH key to the agent, and display the contents of the public key.

```bash
Set-Service -Name ssh-agent -StartupType Automatic
Start-Service ssh-agent
ssh-add "$HOME\.ssh\id_rsa"
Get-Content -Path "$HOME\.ssh\id_rsa.pub"
```

Copy the key generated.

### Adding key to `GitHub`

Go to this link [SSH_Key_GitHub](https://gitHub.com/settings/keys)

Click on `Add SSH Key` and give title `MY_PC_KEY` or anything else you like. Paste the copied key under the key section.

### Cloning the homework repository

Go to your homework repository on GitHub and click on the `Code` button. Copy the SSH link.

![Copying SSH Link](https://gitHub.com/user-attachments/assets/6b36fc76-9af9-4d00-b82e-f175744ce888)

In `Windows Powershell`, run:

```bash
git clone paste-copied-link-here
```

You have successfully cloned your repository.

Enter in your repo through `cd repo-name`

Run `code .` to open repo in VSCode.

You can now **commit** changes, **push**, and **pull** using git commands in your VSCode terminal.
