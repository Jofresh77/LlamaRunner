// Copyright Epic Games, Inc. All Rights Reserved.

#include "LlamaRunnerModule.h"
#include "llama.h"

#define LOCTEXT_NAMESPACE "FLlamaRunnerModule"

void FLlamaRunnerModule::StartupModule()
{
	llama_backend_init();
}

void FLlamaRunnerModule::ShutdownModule()
{
	llama_backend_free();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLlamaRunnerModule, LlamaRunner)