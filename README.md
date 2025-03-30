# LlamaRunner Unreal Engine Plugin
## Overview
This plugin integrates the [llama.cpp](https://github.com/ggml-org/llama.cpp) library into the UE5 ecosystem, allowing game developers to run inferences to imported *.gguf* models during game runtime.
It provides a game instance subsystem, allowing it to be called from almost anywhere inside the UE5 frameworks. A custom subsystem child of the LlamaCppSubsystem class can be created as Blueprint and then configured in the editor to provide the *.gguf* model file path that should be use with the subsystem, as well as other parameters mentionned in the section below.
## Features *(C++ & Blueprint)*
- Common configuration:
  - `.gguf` Model path
  - Model parameters (context size, batches, graphical layers)
- Sampler configuration:
  - Grammar support by providing a `.gbnf` file path
  - Decoding method:
    - Top-P / Top-K
    - Min-P
  - Sampling method:
    - Dist
    - Lazy
    - [Mirostat](https://arxiv.org/abs/2007.14966) (will disable decoding method, as Mirostat uses its own) 
- `AsyncProcessUserPrompt`: takes a string user prompt and a optional system prompt as parameter and runs a asynchronous inference to the model in a background thread task.
- `ClearChatHistory`: speaks to his name. *Note: calling this method will **always** recreate the sampler chain and base its recreation on the current sampler configuration.*
- `SetSamplerConfig`: setter method for the `SamplerConfig` parameter. Act as a Blueprint setter with a custom logic that will **always** call `ClearChatHistory` once it has set the sampler config to a new value.

## Installation
Simply drag and drop the repository root folder inside the Plugins folder of a Unreal Engine project **(it is not recommended to install it directly inside the engine Plugins folder)**.
You must as well download your own `.gguf` model **and** `.gbnf` grammar rules *(grammar rules might become optionnal in the future)* and import then respectively inside the`Resources/Models` and `Resources/Grammars` directories. Then specify their pathes in a custom LlamaCppSubsystem class configuration in the editor.

### Requirements
- OS: Windows
- UE version: 5.5
- A CUDA-based GPU *(i.e. NVIDIA GPU)*
- Having a downloaded `.gguf` model **and** `.gbnf` grammar rules files.

## Next Goals
- Allow to config the model **without** grammar (current state requires one)
- Allow to dynamically switch grammar constraints within the same chat history.
- Add support for decision models.
