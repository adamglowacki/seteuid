# seteuid
Run a program with a list of arguments on behalf of a different user.

Normally you can use `sudo` for that. But in some cases in user namespaces in Linux, you can't use `sudo`. Then you can use this program without SUID bit.
