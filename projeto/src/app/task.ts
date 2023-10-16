export type CategoryType = "shopping" | "health" | "work" | "bills" | "cleaning" | "other";

export interface Task {
    id?: number;
    content: string;
    category?: CategoryType | null;
    isUrgent: boolean;
    doneDate: Date | null;
}