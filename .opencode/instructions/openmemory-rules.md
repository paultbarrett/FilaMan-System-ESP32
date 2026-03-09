**# OpenMemory Rules for Code Projects**

- Use the OpenMemory/Memory tools whenever possible to store and retrieve important project knowledge.
- search openmemory before you inspect folders and files  
- Goal: decisions, code changes, and bug fixes should be saved in a way that they can be reused in new sessions.

**## When Something Should Be Stored**

- **After every major code change**  
  - Create a brief memory note with:  
    - Affected files/modules  
    - What was changed?  
    - Why was it changed? (goal / requirements)  
    - Potential risks or TODOs  
- **For every decision** (API design, architecture, important trade‑offs)  
  - Create a memory note of type “Decision” with:  
    - Context / problem  
    - Considered options  
    - Chosen option  
    - Justification  
- **For every bug fix**  
  - Create a memory note of type “Bugfix” with:  
    - Symptom / error picture (e.g., error message)  
    - Cause  
    - Fix (which files/lines)  
    - What to note for the future  

**## How Memories Should Be Structured**

- Use consistent project tags, e.g., `project:my-project`.  
- Use type tags like `type:decision`, `type:change`, `type:bugfix`.  
- If possible, link commits or exact file paths / line numbers in the note.  

**## Usage in New Sessions or Tasks**

- At the start of a new session or task:  
  - Load the most important OpenMemory entries for the current project (e.g., last decisions, relevant bug fixes).  
  - Create a short overview for yourself before new suggestions are made.  
- If a new error occurs:  
  - First check OpenMemory for previous similar errors, relevant changes or decisions before re‑analyzing the code or making a new decision.  

**# Git Rules**

- **NEVER** push independently to a git repository/branch!