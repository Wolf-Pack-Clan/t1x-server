#!/usr/bin/env bash

if [ ! -x "$(command -v cargo)" ]; then
    printf "Install rust to use this script.\n"
    printf "curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh\n"
fi

set -uo pipefail

if [ ! -x "$(command -v ScriptDocTool)" ]; then
    project_dir="$(realpath .)"
    cd ~
    git clone https://github.com/coyoteclan/ScriptDocTool.git
    cd ScriptDocTool

    cargo build --release
    cargo install --path .

    cd "$project_dir"
fi

# run the doc tool

ScriptDocTool
ScriptDocTool --sort


# Generate a patch to check for issues
git diff --color > patch.patch

# If no patch is generated, all functions have documentation
# and are arranged in alphabetical order
if [ ! -s patch.patch ] ; then
    printf "All functions have documentation ordered alphabetically.\n"
    rm -f patch.patch
    exit 0
fi

# If a patch is generated, display the differences and exit with an error
printf "\n*** The following differences were found between the code "
printf "and the doc rules:\n\n"
cat patch.patch
printf "\n*** Aborting, please fix your commit(s) with 'git commit --amend' or 'git rebase -i <hash>'\n"
rm -f patch.patch
exit 1
