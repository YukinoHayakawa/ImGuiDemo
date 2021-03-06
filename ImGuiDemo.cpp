﻿#include "ImGuiDemo.hpp"

#include <Usagi/Asset/AssetRoot.hpp>
#include <Usagi/Asset/Package/Filesystem/FilesystemAssetPackage.hpp>
#include <Usagi/Game/GameStateManager.hpp>
#include <Usagi/Runtime/Window/Window.hpp>

#include "ImGuiDemoState.hpp"

usagi::ImGuiDemo::ImGuiDemo(std::shared_ptr<Runtime> runtime)
    : GraphicalGame(std::move(runtime))
{
    assets()->addChild<FilesystemAssetPackage>("imgui", "Data/imgui");
    createMainWindow(
        u8"🐰 - ImGui Demo",
        Vector2i { 100, 100 },
        Vector2u32 { 1920, 1080 }
    );
    setupRenderTargets(false);

    mStateManager->pushState<ImGuiDemoState>("ImGuiDemo", this);
}
