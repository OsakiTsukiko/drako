const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const drako = b.addExecutable(.{
        .name = "drako",
        .target = target,
        .optimize = optimize,
    });
    drako.linkLibCpp();
    drako.force_load_objc = true;
    drako.addCSourceFiles(.{
        .files = &[_][]const u8{
            "main.cpp",
            "menu.cpp",
            "global.cpp",
            "ui/node.cpp",
            // nodes
            "ui/nodes/nop.cpp",
            "ui/nodes/comp.cpp",
        },
        .flags = &[_][]const u8{
            "-Wall",
        },
        .root = b.path("src"),
    });
    drako.linkSystemLibrary("raylib");


    b.installArtifact(drako);

    const run_cmd = b.addRunArtifact(drako);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
