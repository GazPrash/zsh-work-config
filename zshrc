autoload -Uz colors && colors


# Zsh only supports 8/16 colors in prompt, so use closest fg colors:
FG_PROMPT='%F{#84a0c6}'
FG_PATH="%F{#b3bbc1}"
FG_ICON="%F{#e27878}"    # peach replaced by yellow here
FG_RESET="%f"

PS1="${FG_PROMPT}%n@Prashants-MacBook-Pro ${FG_PATH}% 󰀵 %~ ${FG_ICON} ${FG_RESET}"

#this for colorful ls
alias ls='ls -G'

# for quick git stuff
alias gs='git status'
alias gr='git reset --hard'

# this for shell autocomplete
autoload -Uz compinit && compinit

# opencode
export PATH=/Users/pshr/.opencode/bin:$PATH
export PATH="$HOME/.local/bin:$PATH"
