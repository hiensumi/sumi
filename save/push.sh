#!/bin/sh
cd Desktop
cd sumi
git init
git remote add origin https://github.com/hiensumi/sumi.git
sudo notify-send "Pulling" --expire-time=5
sudo git pull origin main
sudo git add .
sudo git commit -m "⏁⊑⟒⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏."
sudo notify-send "Pushing" --expire-time=5
sudo git push -f origin main
sudo notify-send "Pushed" --expire-time=5
