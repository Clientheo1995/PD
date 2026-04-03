# Embedded Mini-Game Framework

## Overview
This repository contains the architectural blueprints and core C++ implementations of a custom mini-game framework designed for the Phoenix Dart VSS Machine. 

The primary engineering challenge was to integrate 13+ highly dynamic mini-games into a legacy monolithic state machine while strictly operating within a severely constrained 2GB RAM embedded Linux environment. To achieve this, the framework heavily utilizes the Mediator pattern, Lazy Loading, and various Memory/Rendering Optimizations.

## Tech Stack & Constraints
Language: C++ (Embedded Systems)
Architecture: Component-Based UI, MVC, Data-Driven Pipeline (XML/UI Scripts)
Constraints: 2GB RAM Limit, Real-time Hardware Sensor Synchronization

## Core Architecture & Design Patterns
The mini-games in this repository are categorized by the specific software engineering patterns and optimization techniques they demonstrate:

### 1. Architectural Foundations
[Core Framework] Mediator & Factory Pattern
Concept: Decoupled legacy engine interfaces using a Facade (CNewCheers) and a core manager (NCManager). Implemented ID-based lazy loading to dynamically allocate and explicitly free (SafeDelete) memory during scene transitions, ensuring zero memory leaks.

### 2. State & Lifecycle Management
[Fried Egg] Advanced State Machine
Concept: Granular state routing and precise timer management for asynchronous visual feedback.

[Turn Off Candle] Multi-Object Lifecycle
Concept: Managed independent asynchronous state machines (start, shutdown, loop) for an array of distinct visual entities.

### 3. Rendering & Hardware Synchronization
[Hit The Target] Real-time Angular Math
Concept: Synchronized real-time matrix transformations (UI rotation) with physical hardware LED controllers based on angular calculations.

[Spin Up] State-Driven Velocity Control
Concept: Dynamically mapped mascot narrative states to physical angular velocities (simulated physics in a non-physics engine).

### 4. Memory Optimization & Object Pooling
[Hidden CountUp] UI Object Pooling & Adapter Pattern
Concept: Adapted physical sensor array data to logical game segments and dynamically bound dozens of UI objects via std::vector pooling to avoid hardcoding.

[Hit And Hit] Zero-Allocation Parsing & Stochastic Logic
Concept: Prevented memory fragmentation by using pure mathematics (modulo/division) to render digits instead of string allocations (std::to_string). Handled weight-based RNG scoring.

[Secret Bubble] Dynamic Prefab Instantiation & Post-Processing
Concept: Loaded UI layouts dynamically at runtime (Prefab pattern) and utilized Render Targets (GCanvas) for custom Blur post-processing.

### 5. Advanced Memento Pattern (Undo/Rollback)
[Pirate Roulette] Deterministic RNG & Visual Restoration
Concept: Pre-calculated logic sequences using a deterministic seed for sync safety, and implemented a robust visual rollback system from historical data logs.

[Oh My Ghost] Array-Based Logic & Async Chaining
Concept: Handled low-level buffer serialization for array states and utilized std::bind for non-blocking asynchronous animation chains.

### 6. Event Delegation & Polymorphism
[Breaking Walnuts] MVC Pattern
Concept: Decoupled complex View states (reel spinning, damage levels) from the core Logic, delegating hardware events seamlessly.

[No Bull CountUp] Granular Sensor Mapping
Concept: Evaluated detailed hardware sensor multipliers to trigger complex event-driven character animations.

[Fried Shrimp] Polymorphic Overriding
Concept: Safely overridden the base class's additive scoring logic with a multiplicative geometric progression, handling continuous (looping) audio/visual syncs.

[The Big Number] Component-Based UI
Concept: Fully encapsulated slot machine logic into a standalone, reusable UI Component (CUIObj_SlotMachine) with internal multi-timer staggered stopping logic.

## About me
Heo Suyeon
Software Engineer | Game Programmer
Specializing in C++, Embedded Systems, and Data-Driven Architecture.
https://www.linkedin.com/in/suyeon-heo-856bb1355 | clientheo1995@gmail.com
